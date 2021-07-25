from sparrow._lib.LinearModel import _LinearRegressor

class LinearRegressor:
    def __init__(self):
        self.LR = _LinearRegressor()
    def fit(self, X, y, learning_rate):
        self.LR.fit(X, y, learning_rate)
    def predict(self, X):
        return self.LR.predict(X)
    def get_para(self):
        return self.LR.get_para()