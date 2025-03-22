import numpy as np
import pandas as pd

# 1. 加载数据
df = pd.read_csv('boston_housing_data.csv')
data = df.values
X = data[:, :-1]  # 特征矩阵（排除最后一列）
y = data[:, -1]   # 目标变量（MEDV）

# 2. 手动划分训练集和测试集（8:2比例）
np.random.seed(42)  # 固定随机种子
indices = np.random.permutation(len(X))
train_size = int(0.8 * len(X))
X_train, y_train = X[indices[:train_size]], y[indices[:train_size]]
X_test, y_test = X[indices[train_size:]], y[indices[train_size:]]

# 3. 添加偏置项（截距项）
X_train = np.c_[np.ones(X_train.shape[0]), X_train]
X_test = np.c_[np.ones(X_test.shape[0]), X_test]

# 4. 最小二乘法实现
def least_squares(X, y):
    theta = np.linalg.inv(X.T.dot(X)).dot(X.T).dot(y)
    return theta

theta_ls = least_squares(X_train, y_train)
y_pred_ls = X_test.dot(theta_ls)

# 5. 梯度下降法实现
def feature_scaling(X):
    # 标准化：均值为0，标准差为1
    mean = np.mean(X, axis=0)
    std = np.std(X, axis=0)
    X_scaled = (X - mean) / std
    return X_scaled, mean, std

# 标准化训练集和测试集（注意用训练集的均值和标准差）
X_train_scaled, mean_train, std_train = feature_scaling(X_train[:, 1:])  # 排除偏置项
X_train_scaled = np.c_[np.ones(X_train_scaled.shape[0]), X_train_scaled]  # 重新添加偏置项
X_test_scaled = (X_test[:, 1:] - mean_train) / std_train
X_test_scaled = np.c_[np.ones(X_test_scaled.shape[0]), X_test_scaled]

def gradient_descent(X, y, alpha=0.01, n_iters=1000):
    m, n = X.shape
    theta = np.zeros(n)
    for _ in range(n_iters):
        gradients = (1/m) * X.T.dot(X.dot(theta) - y)
        theta -= alpha * gradients
    return theta

theta_gd = gradient_descent(X_train_scaled, y_train, alpha=0.1, n_iters=1000)
y_pred_gd = X_test_scaled.dot(theta_gd)

# 6. 手动计算评估指标
def mse(y_true, y_pred):
    return np.mean((y_true - y_pred)**2)

def r2_score(y_true, y_pred):
    sse = np.sum((y_true - y_pred)**2)
    sst = np.sum((y_true - np.mean(y_true))**2)
    return 1 - (sse / sst)

# 评估结果
print("最小二乘法结果：")
print(f"MSE: {mse(y_test, y_pred_ls):.2f}")
print(f"R²: {r2_score(y_test, y_pred_ls):.2f}\n")

print("梯度下降法结果：")
print(f"MSE: {mse(y_test, y_pred_gd):.2f}")
print(f"R²: {r2_score(y_test, y_pred_gd):.2f}")