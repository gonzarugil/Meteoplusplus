# Import Libraries

import tweepy
import serial
import time


# Setup of bluetooth

BT = serial.Serial("/dev/rfcomm0",9600,timeout=10)
print("Bluetooth is connected succesfully")

# Setup of Twitter
auth = tweepy.OAuthHandler('xOca0pffD13sxRvY0mTdR9Kef', 'T62Pl6IpqJ9MkvHEIjf7ooNG2yqZODQ1c5dFijbxzfPRPQxNS5')
auth.set_access_token('716272805042601986-Is7aB8RKV8DaLp8WqMbJmSH9CpFd2ze',
                      'TrZ62MZXW7dE1AZj0vUP4A6m2cipUEvunWzsKT2xH1epr')
api = tweepy.API(auth)

while(True):
    # Check of mentions in twitter
    mentions = api.mentions_timeline()
    for tweet in mentions:
        list = tweet.text.split()
        if set(["#weather", "#temperature", "#humidity", "#ground","#rain","#pressure"]).intersection(set(list)):
            twid = tweet.id
            sn = tweet.user.screen_name
            replies = api.search(q=sn, sinceId=twid)
            found = False
            for e in replies:
                if e.in_reply_to_status_id == twid:
                    found = True
                    break
            if not found:
                # This is where we ask arduino for the data
                if "#weather" in list:
                    BT.write("1".encode('utf-8'))
                elif "#humidity" in list:
                    BT.write("2".encode('utf-8'))
                elif "#temperature" in list:
                    BT.write("3".encode('utf-8'))
                elif "#ground" in list:
                    BT.write("4".encode('utf-8'))
                elif "#rain" in list:
                    BT.write("5".encode('utf-8'))
                elif "#pressure" in list:
                    BT.write("6".encode('utf-8'))

                # Here we receive the response and tweet it
                btresponse = BT.readline()
                decoded = btresponse.decode('utf-8')
                if decoded != "":
                    reply = "@{0} {1}".format(sn, decoded)
                    print("twitteando:" + reply)
                    api.update_status(reply, twid)

    time.sleep(60)
    print("application running")
                # ------------------------------------------

