from selenium import webdriver
from selenium.webdriver.common.keys import Keys

# 启动浏览器
driver = webdriver.Chrome("C:\\Users\\hf01\\Music\\chromedriver.exe")

# 打开目标页面
driver.get("http://note.ms/1")

# 找到输入框
input_box = driver.find_element_by_id("note-input")

# 模拟输入文本
input_box.send_keys("This is my note.")

# 直接触发保存操作
driver.execute_script("saveNote();")

# 关闭浏览器
driver.quit()
