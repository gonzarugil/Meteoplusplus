# Import Libraries

import tweepy

# api = twitter.Api(consumer_key='xOca0pffD13sxRvY0mTdR9Kef',
#                  consumer_secret='T62Pl6IpqJ9MkvHEIjf7ooNG2yqZODQ1c5dFijbxzfPRPQxNS5',
#                  access_token_key='716272805042601986-Is7aB8RKV8DaLp8WqMbJmSH9CpFd2ze',
#                  access_token_secret='TrZ62MZXW7dE1AZj0vUP4A6m2cipUEvunWzsKT2xH1epr')


auth = tweepy.OAuthHandler('xOca0pffD13sxRvY0mTdR9Kef', 'T62Pl6IpqJ9MkvHEIjf7ooNG2yqZODQ1c5dFijbxzfPRPQxNS5')
auth.set_access_token('716272805042601986-Is7aB8RKV8DaLp8WqMbJmSH9CpFd2ze', 'TrZ62MZXW7dE1AZj0vUP4A6m2cipUEvunWzsKT2xH1epr')

api = tweepy.API(auth)

mentions = api.mentions_timeline()
for tweet in mentions:
    list = tweet.text.split()
    if "#weather" in list:
        print("i'll check replies")
        id = tweet.id
        sn = tweet.user.screen_name
        replies = api.search(q=sn, sinceId=id)
        found = False
        for e in replies:
            if e.in_reply_to_status_id == id:
                found = True
                break
        if not found:
            # This is where we ask arduino for the data
            
            # ------------------------------------------
            reply = "@%s Hello again!" % sn
            api.update_status(reply,tweet.id)

# Welcome message

