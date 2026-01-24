import csv
import math


class Data:
    def __init__(self):
        self.ages = []
        self.payment_amounts = []


def average_age(data):
    return sum(data.ages) / len(data.ages)


def average_payment_amount(data):
    return sum(data.payment_amounts) / len(data.payment_amounts)


def stddev_payment_amount(data):
    mean = average_payment_amount(data)
    squared_diffs = sum((amt - mean) ** 2 for amt in data.payment_amounts)
    return math.sqrt(squared_diffs / len(data.payment_amounts))


def load_data():
    data = Data()

    with open('users.csv') as f:
        for line in csv.reader(f):
            age = int(line[2])
            data.ages.append(age)

    with open('payments.csv') as f:
        for line in csv.reader(f):
            amount_cents = int(line[0])
            data.payment_amounts.append(amount_cents / 100.0)

    return data



