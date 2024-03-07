#!/usr/bin/env python
# coding: utf-8

# In[6]:


for i in range(10):
    print("hey guys")


# 编写一个计算闰年的代码
# 输入：2000
# 输出：Y
# 
# 输入：1997
# 输出：N
# 

# In[9]:


years = int(input("输入一个年份，判断是否是闰年"))
if years % 400 == 0 or (years % 100 != 0 and years % 4 ==0):
    print("Y")
else:
    print("N")


# # 1、导入库文件

# In[17]:


import tensorflow as tf           #导入
import pandas     as pd
import matplotlib.pyplot as plt
get_ipython().run_line_magic('matplotlib', 'inline')


# # 2、数据集导入

# In[20]:


data = pd.read_csv(r'E:\2023269046\Income.csv')


# In[21]:


data


# In[23]:


plt.scatter(data.Education, data.Income)
plt.xlabel('Education')
plt.ylabel("Income")
plt.title('2023269046')


# # 3、模型搭建

# In[24]:


model = tf.keras.Sequential()
model.add(tf.keras.layers.Dense(1,input_shape=(1,) ))


# In[25]:


model.summary() # y=wx+b


# # 4、训练配置

# In[26]:


model.compile(optimizer='adam',
              loss='mse',
              metrics='mse'
)


# # 5、训练

# In[27]:


model.fit(data.Education,
         data.Income,
         epochs=10
)


# In[29]:


y_preed = model.predict(data.Education)

plt.scatter(data.Education,data.Income)
plt.plot(data.Education, y_preed, c='red')
plt.xlabel("Education")
plt.ylabel("Income")
plt.title("2023269046")


# In[33]:


model.fit(data.Education,
         data.Income,
         epochs=10000
)


# In[34]:


y_preed = model.predict(data.Education)

plt.scatter(data.Education,data.Income)
plt.plot(data.Education, y_preed, c='red')
plt.xlabel("Education")
plt.ylabel("Income")
plt.title("2023269046")


# In[35]:


model.fit(data.Education,
         data.Income,
         epochs=100


# # 6、模型评估和预测

# In[37]:


model.evaluate(data.Education, data.Income)


# In[38]:


y_pred = model.predict(data.Education)


# In[39]:


data.Education[:5],y_pred[:5]


# In[40]:


model.weights


# y = wx+b

# # 7、模型的保存和加载

# In[41]:


model.save(r'E:\2023269046\model\2024_03_07.h5')


# In[42]:


loader_model = 0


# In[43]:


loader_model = tf.keras.models.load_model(r'E:\2023269046\model\2024_03_07.h5') #读取模型


# In[ ]:





# In[44]:


loader_model.weights


# In[45]:


y_pred = loader_model.predict(data.Education)


# In[46]:


plt.scatter(data.Education, data.Income)
plt.plot(data.Education, y_pred, c = "green")
plt.xlabel("Education")
plt.ylabel("Income")
plt.title("2023269046")


# In[ ]:





# In[ ]:





# In[ ]:




