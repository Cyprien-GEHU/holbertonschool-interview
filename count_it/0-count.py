#!/usr/bin/python3
""" function to count sorted count of given keywords"""
import requests

def count_words(subreddit, word_list, after=None, counter=None) :
    """ count and show a sorted occurent post hot topic"""
    if counter is None :
        counter = {}
        word_list = [word.lower() for word in word_list]
        for word in word_list:
            counter[word] = counter.get(word,0)

    URL = "https://www.reddit.com/r/{}/hot.json".format(subreddit)
    parameters = {"limit": 100, "after": after}
    headers = {"User-Agent": "python:count_words:v1.0"}
    try:
        response_redit = requests.get(URL, headers=headers, params=parameters, allow_redirects=False)
    except requests.RequestException:
        return
    
    if response_redit.status_code != 200:
        return
    
    try:
        data_redit = response_redit.json()
    except Exception:
        return
    
    posts_redit = data_redit.get("data", {}).get("children", [])
    for post in posts_redit:
        title = post.get("data", {}).get("title", "")
        word_title = title.lower().split()
        for w in word_title:
            if w in counter:
                counter[w] += 1

    after = data_redit.get("data", {}).get("after")
    if after is not None:
        return count_words(subreddit, word_list, after, counter)
    
    items_word = [(key, value) for key, value in counter.items() if value > 0]
    items_word.sort(key=lambda x: (-x[1], x[0]))
    for key, value in items_word:
        print("{}: {}".format(key, value))