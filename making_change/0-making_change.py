#!/usr/bin/python3
"""  pile of coins of different values,
determine the fewest number of coins needed to meet a given amount """


def makeChange(coins, total):
    """ determine the fewest number of coin needed to have the total"""

    if total <= 0:
        return 0

    dp = [float('inf')] * (total + 1)
    dp[0] = 0

    for coin in coins:
        for count in range(coin, total + 1):
            dp[count] = min(dp[count], dp[count - coin] + 1)

    if dp[total] == float('inf'):
        return -1

    return dp[total]
