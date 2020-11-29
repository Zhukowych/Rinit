import mysql.connector
mydb = mysql.connector.connect(
  host="192.168.11.132",
  user="max",
  password="beatles",
  database="hmarka"
)

mycursor = mydb.cursor()
mycursor.execute("SELECT user_id, product_id, count FROM history_product")
for i in mycursor.description:
    print(i[0])
