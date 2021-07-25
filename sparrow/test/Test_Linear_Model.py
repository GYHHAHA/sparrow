from sparrow.models.LinearModel import LinearRegressor

if __name__=="__main__":
    X = [1,2,3]
    y = [1,2,3]
    LR = LinearRegressor()
    LR.fit(X,y,0.01)
    print(LR.predict([1,2,3]))
    print(LR.get_para())