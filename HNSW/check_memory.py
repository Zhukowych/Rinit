import mysql.connector

mydb = mysql.connector.connect(
  host="192.168.11.132",
  user="max",
  password="beatles",
  database="hmarka"
)

mycursor = mydb.cursor()

#mycursor.execute("CREATE TABLE user_vectors(user_id INT, user_vector VARCHAR(100));")
#mycursor.execute("INSERT INTO user_vectors (user_id, user_vector) VALUES (1, '12'), (2, '1234')")
#mycursor.execute("TRUNCATE TABLE user_vectors")
mycursor.execute("SELECT * FROM user_vectors")

for i in mycursor:
    print(i)
