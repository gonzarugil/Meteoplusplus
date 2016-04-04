# Import Libraries

import twitter
import serial
import time

api = twitter.Api(consumer_key='xOca0pffD13sxRvY0mTdR9Kef',
                  consumer_secret='T62Pl6IpqJ9MkvHEIjf7ooNG2yqZODQ1c5dFijbxzfPRPQxNS5',
                  access_token_key='716272805042601986-Is7aB8RKV8DaLp8WqMbJmSH9CpFd2ze',
                  access_token_secret='TrZ62MZXW7dE1AZj0vUP4A6m2cipUEvunWzsKT2xH1epr')

# Welcome message
print('Welcome To Meteo ++!')

status = []
x = 0
status = api.GetUserTimeline(screen_name='gonzarugil')  # grab latest statuses
checkIt = [s.text for s in status]  # put status in an array


print(checkIt[0])
