import pandas as pd
import numpy as np
import os
import matplotlib.pyplot as plt
import datetime as dt
import KNNLearner as knn

# %matplotlib inline
# select stock and obtain all the stock data
def symbol_to_path(symbol, base_dir=os.path.join("..", "data")):
    """Return CSV file path given ticker symbol."""
    return os.path.join(base_dir, "{}.csv".format(str(symbol)))

def get_data(symbols, dates, addSPY=False):
    """Read stock data (adjusted close) for given symbols from CSV files."""
    df = pd.DataFrame(index=dates)
    if addSPY and 'SPY' not in symbols:  # add SPY for reference, if absent
        symbols = ['SPY'] + symbols
    for symbol in symbols:
        df_temp = pd.read_csv(symbol_to_path(symbol), index_col='Date',
                parse_dates=True, usecols=['Date', 'Adj Close'], na_values=['nan'])
        df_temp = df_temp.rename(columns={'Adj Close': symbol})
        df = df.join(df_temp)
        if symbol == 'SPY':  # drop dates SPY did not trade
            df = df.dropna(subset=["SPY"])

    return df
def get_price(date, symbol):
    date_prev = date - dt.timedelta(days=1)
    date_prev = date_prev.strftime('%y-%m-%d')
    df_current = get_data([symbol], [date], False)
    df_current_price = df_current.ix[date][symbol]
    return df_current_price

def compute_portvals(orderForm, start_val = 1000000):
    # this is the function the autograder will call to test your code
    # TODO: Your code here

    # setup the position table
    df = orderForm
#     print df
    symbols = df[:]['Symbol']
    symbols = symbols.drop_duplicates()
    symbols = symbols.tolist()
    dates = df[:]['Date']
    endDate = (dates.max())
    startDate = (dates.min())
    date_range = pd.date_range(startDate, endDate, freq='D')
    df_ret = pd.DataFrame(index=date_range,columns=symbols)
    
    newList = np.zeros([1,np.size(symbols)])
    shareOffset = pd.DataFrame(data=newList, columns=symbols)
    portvals = pd.DataFrame(index=date_range, columns=['portfolio'],dtype=float);
    for dates in date_range:
        for symbol in symbols:
            df_ret.ix[dates][symbol] = ([0,0,0,0]) #initialize [trading action, stockPrice, shares,totalCash,deltaShare
    
    #adding all the trading actions in ret dataframe +1 buy, -1 sell, 0 hold
    for i in range(0,df.shape[0]):
        date = df.ix[i][0]
        symbol = df.ix[i][1]
        orderType = df.ix[i][2]
        shares = df.ix[i][3]          
        if(orderType == 'BUY'):
            df_ret.ix[date][symbol][0] = 1
            df_ret.ix[date][symbol][2] = df_ret.ix[date][symbol][2] + shares
        else:
            df_ret.ix[date][symbol][0] = -1
            df_ret.ix[date][symbol][2] = df_ret.ix[date][symbol][2] - shares
    for dates in date_range:
        for symbol in symbols:
            df_ret.ix[dates][symbol][1] = get_price(date=dates,symbol=symbol)
            if (dates != df_ret.index[0]):
                date_prev = dates - dt.timedelta(days=1)
                df_ret.ix[dates][symbol][2] = df_ret.ix[dates][symbol][2] + df_ret.ix[date_prev][symbol][2]
#     pd.set_option('display.max_rows', len(df_ret))
    skip1 = True
    for dates in date_range:
        dates = dates.date()
        for symbol in symbols:
            if(skip1):
                df_ret.ix[dates][symbol][3] = df_ret.ix[dates][symbol][2]
                continue
            date_prev = dates - dt.timedelta(days=1)
            df_ret.ix[dates][symbol][3] = df_ret.ix[dates][symbol][2] - df_ret.ix[date_prev][symbol][2]
        if(skip1):
            skip1 = False

            
# taking care of trade along time
    preDate = startDate
    currentCash = start_val
    preCash = 0
    preLeverage = 0
    # calculating current cash
    for dates in date_range:    
        sumLong = 0
        sumShort = 0
        checkLeverage = False
        for symbol in symbols:
            if np.isnan(df_ret.ix[dates][symbol][1]):
                break
            currentCash = currentCash - df_ret.ix[dates][symbol][1] * df_ret.ix[dates][symbol][3]
    # calculating current invested position
        currentInvested = 0
        for symbol in symbols:
            if np.isnan(df_ret.ix[dates][symbol][1]):
                break
            if ((df_ret.ix[dates][symbol][2] + shareOffset.ix[0][symbol]) < 0):
                sumShort = sumShort + df_ret.ix[dates][symbol][1] * (df_ret.ix[dates][symbol][2] + shareOffset.ix[0][symbol])
            if ((df_ret.ix[dates][symbol][2] + shareOffset.ix[0][symbol]) >= 0):
                sumLong = sumLong + df_ret.ix[dates][symbol][1] * (df_ret.ix[dates][symbol][2] + shareOffset.ix[0][symbol])
            currentInvested = currentInvested + df_ret.ix[dates][symbol][1] * (df_ret.ix[dates][symbol][2] + shareOffset.ix[0][symbol])
        leverage = (sumLong - sumShort)/(sumLong + sumShort + currentCash)
        
        if np.isnan(df_ret.ix[dates][symbol][1]):
                continue
#         print 'leverage = ',leverage
        #check if drop the trade activitiy
#         if (leverage > 200000000000000 and leverage > preLeverage):
# #             print 'checked out: ',preLeverage
#             for symbol in symbols:
#                 shareOffset.ix[0][symbol] = shareOffset.ix[0][symbol] - df_ret.ix[dates][symbol][3]
#             currentCash = preCash
# # calculating current invested position
#             currentInvested = 0
#             for symbol in symbols:
#                 currentInvested = currentInvested + df_ret.ix[dates][symbol][1] * (df_ret.ix[dates][symbol][2] + shareOffset.ix[0][symbol])
        portvals.ix[dates]['portfolio'] = currentCash + currentInvested   
        preCash = currentCash
        preLeverage = leverage
  
    portvals = (portvals.dropna())
#     print portvals
    return portvals

def generateOrderBook(longSignal,shortSignal,outSignal,n_mmt):
#generate order book
    orderBook = pd.DataFrame(columns=['Date','Symbol','Order','Shares'])
    prevOrder = 0 # 0 is exit 1 is long -1 is short
    for ind in range(longSignal.shape[0]):
        if ind == 0:
            if(longSignal[ind]):
                newData = pd.DataFrame(columns=['Date','Symbol','Order','Shares'],data=[[n_mmt.index[0].date(),symbol,'BUY',100]])
                orderBook.loc[orderBook.shape[0],:] = (newData.values)
                prevOrder = 1
            elif(shortSignal[ind]):
                newData = pd.DataFrame(columns=['Date','Symbol','Order','Shares'],data=[[n_mmt.index[0].date(),symbol,'SELL',100]])
                orderBook.loc[orderBook.shape[0],:] = (newData.values)
                prevOrder = -1
            continue
        if (prevOrder == 0):
            if (longSignal[ind]):
                newData = pd.DataFrame(columns=['Date','Symbol','Order','Shares'],data=[[n_mmt.index[ind].date(),symbol,'BUY',100]])
                prevOrder = 1
                orderBook.loc[orderBook.shape[0],:] = (newData.values)
            elif (shortSignal[ind]):
                newData = pd.DataFrame(columns=['Date','Symbol','Order','Shares'],data=[[n_mmt.index[ind].date(),symbol,'SELL',100]])
                prevOrder = -1
                orderBook.loc[orderBook.shape[0],:] = (newData.values)
        elif (prevOrder == 1):
            if (outSignal[ind]):
                newData = pd.DataFrame(columns=['Date','Symbol','Order','Shares'],data=[[n_mmt.index[ind].date(),symbol,'SELL',100]])
                prevOrder = 0
                orderBook.loc[orderBook.shape[0],:] = (newData.values)
            elif (shortSignal[ind]):
                newData = pd.DataFrame(columns=['Date','Symbol','Order','Shares'],data=[[n_mmt.index[ind].date(),symbol,'SELL',200]])
                prevOrder = -1
                orderBook.loc[orderBook.shape[0],:] = (newData.values)
        elif (prevOrder == -1):
            if (outSignal[ind]):
                newData = pd.DataFrame(columns=['Date','Symbol','Order','Shares'],data=[[n_mmt.index[ind].date(),symbol,'BUY',100]])
                prevOrder = 0
                orderBook.loc[orderBook.shape[0],:] = (newData.values)
            elif (longSignal[ind]):
                newData = pd.DataFrame(columns=['Date','Symbol','Order','Shares'],data=[[n_mmt.index[ind].date(),symbol,'BUY',200]])
                prevOrder = 1
                orderBook.loc[orderBook.shape[0],:] = (newData.values)
    return orderBook

def generateSignal(predY,signalThreshold, signalThreshold2):
    #generate signals
    longSignal = np.empty((predY.shape))
    outSignal = np.empty((predY.shape))
    shortSignal = np.empty((predY.shape))
    for i in range(predY.shape[0]):
        if (i == 0):
            if (predY[i] > signalThreshold):
                shortSignal[i] = False
                outSignal[i] = False
                longSignal[i] = True
            elif (predY[i] < -signalThreshold):
                shortSignal[i] = True
                outSignal[i] = False
                longSignal[i] = False
            else:
                shortSignal[i] = False
                outSignal[i] = True
                longSignal[i] = False
        else:
            if (predY[i] > signalThreshold):
                shortSignal[i] = False
                outSignal[i] = False
                longSignal[i] = True
            elif (predY[i] < -signalThreshold):
                shortSignal[i] = True
                outSignal[i] = False
                longSignal[i] = False
            else:
                if (predY[i] > -signalThreshold2 and longSignal[i-1]):
                    shortSignal[i] = False
                    outSignal[i] = False
                    longSignal[i] = True
                elif (predY[i] <= -signalThreshold2 and longSignal[i-1]):
                    shortSignal[i] = False
                    outSignal[i] = True
                    longSignal[i] = False
                elif (predY[i] < signalThreshold2 and shortSignal[i-1]):
                    shortSignal[i] = True
                    outSignal[i] = False
                    longSignal[i] = False
                elif (predY[i] >= signalThreshold2 and shortSignal[i-1]):
                    shortSignal[i] = False
                    outSignal[i] = True
                    longSignal[i] = False
                else:
                    shortSignal[i] = False
                    outSignal[i] = True
                    longSignal[i] = False
    adjustLong = pd.DataFrame(index=df[symbol][windowSize-1:].index,data=longSignal)
    adjustShort = pd.DataFrame(index=df[symbol][windowSize-1:].index,data=shortSignal)
    adjustOut = pd.DataFrame(index=df[symbol][windowSize-1:].index,data=outSignal)
    maxVal = df[symbol][windowSize-1:].max()
    maxVal = maxVal * 1.1
    minVal = df[symbol][windowSize-1:].min()
    minVal = minVal - abs(minVal)*0.15
    plt.subplots(1,sharex=True, figsize=(15,10))
    plt.plot(adjustLong*maxVal,'g')
    plt.plot(adjustShort*maxVal,'r')
    plt.plot(adjustOut*maxVal,'black')
    plt.plot(df[symbol][windowSize-1:],'b')
    plt.legend(['Long Signal','Short Signal','Exit Signal','Price'])
    plt.title('Entry/Exit Signal')
    plt.ylim([minVal,maxVal*1.1])
    return longSignal,shortSignal,outSignal

def future5cumRet(inputdf,start_date,windowSize):
    newDF = inputdf.ix[start_date:]
    d_ret = newDF.pct_change();
    for ind in range(newDF.shape[0]):
        subDF = d_ret[ind:ind+windowSize]
        new_d_ret = subDF.cumsum(0)
        newDF.ix[ind] = new_d_ret.ix[-1]
#     newDF = newDF[:-4]
    return newDF

def bbVal(inputdf,windowSize):
    rollMean = pd.rolling_mean(inputdf,windowSize).dropna()
    rollStd  = pd.rolling_std(inputdf,windowSize).dropna()
    newDF = inputdf.ix[windowSize-1:]
    newDF = (newDF - rollMean)/(2*(rollStd))
    return newDF
    
def findMomentum(inputdf, windowSize):
    newDF = inputdf.ix[windowSize-1:]
    midDF = inputdf.shift(windowSize-1).dropna()
    retDF = (newDF/midDF)-1
    return retDF

def calcMACD(inputdf,smallWindow,largeWindow):
    cSmall = (smallWindow-1)/2.0
    cLarge = (largeWindow-1)/2.0
    smallEMA = pd.ewma(inputdf,com=cSmall)
    largeEMA = pd.ewma(inputdf,com=cLarge)
    retDF = smallEMA - largeEMA
    return retDF

def normalizeData(inputdf):
    newDF = (inputdf-inputdf.mean())/df.std()
    return newDF

if __name__ == "__main__":

    symbols = ['SPY','ML4T-240','IBM','AAPL','XOM']
    testSymbols = ['IBM']
    windowSize = 5
    
    trainModel = True
    # trainModel = False
    signalThreshold = 0.025
    signalThreshold2 = 0.01 #a positive number
    if (trainModel):
        #=================================#
        #SINE out-of-sample training & testing
        #=================================#    
        dates = pd.date_range('2007-12-31','2009-12-31', freq='D')
        df = get_data(symbols, dates)
        start_date = dt.date(2007,12,31)
        #training output value for training
        fu5Ret = future5cumRet(df,start_date,windowSize)
        #===============================#
        #training future 1 bollinger band value
        bbValue = bbVal(df,windowSize)

        #training feature 2 Momentum
        mmt = findMomentum(df,windowSize)

        #training feature 3 MACD
        macd = calcMACD(df,12,26)
        #=================================#
        #assign the data by throwing out first a few days
        fu5Ret = fu5Ret.ix[mmt.index[0].date():]
        macd = macd.ix[mmt.index[0].date():]

        # normalize training data
        n_bbValue = normalizeData(bbValue)
        n_mmt = normalizeData(mmt)
        n_macd = normalizeData(macd)

    else:
        #=================================#
        #SINE out-of-sample testing
        #=================================#
        dates = pd.date_range('2009-12-31','2011-12-31', freq='D')
        df = get_data(symbols, dates)
        start_date = dt.date(2009,12,31)

        #===============================#
        #training output value for training
        fu5Ret = future5cumRet(df,start_date,windowSize)
        #===============================#
        #training future 1 bollinger band value
        bbValue = bbVal(df,windowSize)

        #training feature 2 Momentum
        mmt = findMomentum(df,windowSize)

        #training feature 3 MACD
        macd = calcMACD(df,12,26)
        #=================================#
        #assign the data by throwing out first a few days
        fu5Ret = fu5Ret.ix[mmt.index[0].date():]
        macd = macd.ix[mmt.index[0].date():]

        # normalize training data
        n_bbValue = normalizeData(bbValue)
        n_mmt = normalizeData(mmt)
        n_macd = normalizeData(macd)
    #Train the KNN model and visualize the training/predicting of future 5 day cumulative return
    # Or testing the model with out-of-sample testing dataset
    if (trainModel):
        for symbol in testSymbols:
            #prepare training dataset
            trainX = np.empty((n_mmt.shape[0],3))
            trainX[:,0] = n_mmt[symbol].values
            trainX[:,1] = n_bbValue[symbol].values
            trainX[:,2] = n_macd[symbol].values
            trainY = (fu5Ret[symbol].values)
            learner = knn.KNNLearner(k = 3, verbose = False) # constructor
            learner.addEvidence(trainX, trainY) # training step
            # prediction on in-sample sine-fast data
            predY = learner.query(trainX)
#             n_ave = 3
#             predY = np.convolve(predY, np.ones(n_ave)/n_ave, mode='same')
            adjustTrainY = df[symbol][windowSize-1:].values*(trainY+1)
            adjustPredY = df[symbol][windowSize-1:].values*(predY+1)
            adjustTrainY = pd.DataFrame(index=df[symbol][windowSize-1:].index,data=adjustTrainY)
            adjustPredY = pd.DataFrame(index=df[symbol][windowSize-1:].index,data=adjustPredY)
            plt.subplots(1,sharex=True, figsize=(15,10))
            plt.plot(adjustTrainY,'b')
            plt.plot(adjustPredY,'r')
            plt.plot(df[symbol][windowSize-1:],'g')
            plt.legend(['trainY','predY','Price'])
            plt.title('In-Sample')
    else:
        for symbol in testSymbols:
            #prepare training dataset
            testX = np.empty((n_mmt.shape[0],3))
            testX[:,0] = n_mmt[symbol].values
            testX[:,1] = n_bbValue[symbol].values
            testX[:,2] = n_macd[symbol].values
            testY = (fu5Ret[symbol].values)
            # prediction on in-sample sine-fast data
            predY = learner.query(testX)
#             n_ave = 3
#             predY = np.convolve(predY, np.ones(n_ave)/n_ave, mode='same')
            adjustTestY = df[symbol][windowSize-1:].values*(testY+1)
            adjustPredY = df[symbol][windowSize-1:].values*(predY+1)
            adjustTestY = pd.DataFrame(index=df[symbol][windowSize-1:].index,data=adjustTestY)
            adjustPredY = pd.DataFrame(index=df[symbol][windowSize-1:].index,data=adjustPredY)
            plt.subplots(1,sharex=True, figsize=(15,10))
            plt.plot(adjustTestY,'b')
            plt.plot(adjustPredY,'r')
            plt.plot(df[symbol][windowSize-1:],'g')
            plt.legend(['testY','predY','Price'])
            plt.title('out-of-Sample')

    # generate signals and plot it based on either in-sample or out-of-sample dataset
    longSignal,shortSignal,outSignal = generateSignal(predY,signalThreshold,signalThreshold2)
    #To do the backtest, generating the orderbook of the portfolio
    orderBook = generateOrderBook(longSignal,shortSignal,outSignal,n_mmt)
    # calculate the return of the portfolio
    portRet = compute_portvals(orderBook,100000)
    # normalize portret and compare with SPY with normalization
    dailyret = portRet/portRet.ix[0]
    spyDailyRet = df['SPY']/df['SPY'][0]
    plt.subplots(1,sharex=True, figsize=(15,10))
    plt.plot(dailyret)
    plt.plot(spyDailyRet)
    plt.legend(['portfolio','SPY'])
    plt.title('backtest')

