import pymysql
conn = pymysql.connect(host='localhost', user='root', password='raspberrypi')
conn.cursor().execute('create database newdb2')
