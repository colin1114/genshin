from selenium import webdriver
from selenium.webdriver.common.by import By
import time

# 启动浏览器
driver = webdriver.Chrome()

try:
    # 循环访问 note.ms/1 到 note.ms/200
    for i in range(1, 201):
        url = f'http://note.ms/{i}'
        driver.get(url)

        # 填写表单
        textarea = driver.find_element(By.CLASS_NAME, 'content')  # 根据实际的 HTML 结构调整定位
        textarea.clear()
        textarea.send_keys("hello")

        # 提交表单（假设有提交按钮）
        submit_button = driver.find_element(By.NAME, 'submit')  # 根据实际按钮的属性替换
        submit_button.click()

        print(f"Successfully submitted 'hello' to {url}.")
        time.sleep(1)  # 保持页面打开1秒

finally:
    # 关闭浏览器
    driver.quit()
