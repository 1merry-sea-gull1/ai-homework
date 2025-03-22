import pandas as pd
import matplotlib.pyplot as plt
import seaborn as sns

plt.rcParams['font.sans-serif'] = ['SimHei']  # 设置中文字体为黑体
plt.rcParams['axes.unicode_minus'] = False    # 解决负号显示问题

# 1. 加载数据集
df = pd.read_csv('boston_housing_data.csv')  # 确保文件路径正确

# 2. 数据预处理
# 检查缺失值
print("缺失值统计：\n", df.isnull().sum())

# 数据摘要
print("\n数据摘要：\n", df.describe())

# 3. 数据分析：特征与目标变量的相关性
corr = df.corr()
plt.figure(figsize=(12, 8))
sns.heatmap(corr, annot=True, fmt=".2f", cmap='coolwarm')
plt.title("特征与房价（MEDV）的相关性热力图")
plt.show()
#由图，可以得到RM与MEDV中度正相关，LSTAT和PIRATIO与RM中度负相关

# 4. 可视化分析（多角度）
# 获取所有列名（特征名称）
columns = df.columns.tolist()

# 创建多子图布局（4行4列，共16个子图，实际使用14个）
fig, axes = plt.subplots(nrows=4, ncols=4, figsize=(20, 20))
axes = axes.flatten()  # 将子图展平为一维数组

# 遍历每个特征绘制直方图
for i, col in enumerate(columns):
    sns.histplot(df[col], bins=30, kde=True, ax=axes[i])
    axes[i].set_title(f'{col}的分布', fontsize=12)
    axes[i].set_xlabel('')
    axes[i].set_ylabel('频次')

# 隐藏多余的子图
for j in range(len(columns), len(axes)):
    axes[j].set_visible(False)

plt.tight_layout()
plt.show()

# 关键特征与房价的散点图
fig, axes = plt.subplots(1, 3, figsize=(18, 5))
sns.scatterplot(x='RM', y='MEDV', data=df, ax=axes[0])
axes[0].set_title("RM与房价关系")
sns.scatterplot(x='LSTAT', y='MEDV', data=df, ax=axes[1])
axes[1].set_title("LSTAT与房价关系")
sns.scatterplot(x='PIRATIO', y='MEDV', data=df, ax=axes[2])  # 修改此处列名
axes[2].set_title("PIRATIO与房价关系")  # 更新标题避免歧义
plt.tight_layout()
plt.show()
#RM和LSTAT与MEDV有明显的线性相关性，而PIRATIO与MEDV没有明显的线性相关性

# 异常值检查：箱线图
plt.figure(figsize=(10, 6))
sns.boxplot(data=df[['CRIME', 'ZN', 'INDUS', 'CHAS', 'NOX', 'RM', 'AGE', 'DIS', 'RAD', 'TAX', 'PTRATIO', 'LSTAT', 'MEDV']])
plt.title("特征与房价的箱线图（异常值检测）")
plt.xticks(rotation=45)
plt.show()

import numpy as np
import pandas as pd




