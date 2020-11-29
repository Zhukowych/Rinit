import mysql.connector
mydb = mysql.connector.connect(
    host="192.168.11.132",
    user="max",
    password="beatles",
    database="hmarka"
)

mycursor = mydb.cursor()


#mycursor.execute("TRUNCATE TABLE user_vectors")
mycursor.execute("SELECT * FROM user_vectors WHERE user_id="+str(2074))
num_fields = len(mycursor.description)
field_names = [i[0] for i in mycursor.description]
for i in mycursor:
    print(i)
#myresult = mycursor.fetchall()
#for i in myresult:
#    print(i)



