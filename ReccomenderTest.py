import mysql.connector
import random as rd
mydb = mysql.connector.connect(
    host="192.168.11.132",
    user="max",
    password="beatles",
    database="hmarka"
)
mycursor = mydb.cursor()
#name


def get_already(user_id):
    global mycursor
    print("already visited: ")
    mycursor.execute("SELECT product_id FROM history_product WHERE user_id=%s"%user_id)
    product_ids = []
    result = mycursor.fetchall()
    for i in result:
        product_ids.append(i[0])

    for i in product_ids:
        mycursor.execute("SELECT name FROM product WHERE id=%s"%str(i))
        for j in mycursor:
            print("ID:", str(i), j[0])
    print("---------")

def get_recomendations(user_id):
    global mycursor
    print("reccomended: ")
    mycursor.execute("SELECT * FROM recccomendations WHERE user_id=%s"%user_id)
    product_ids = []
    result = mycursor.fetchall()
    for i in result:
        product_ids = str(i[1]).split(" ")
        product_ids.pop()
    
    for i in product_ids:
        
        mycursor.execute("SELECT name FROM product WHERE id=%s"%str(i))
        for j in mycursor:
            print("ID:", str(i), j[0])
    
    print("==========")

    

def get_random_user():
    global mycursor
    ids = []
    mycursor.execute("SELECT user_id FROM history_product")
    for i in mycursor:
        ids.append(i[0])
    for i in rd.sample(ids, 20):
        print(i)
    
def main():
    get_random_user()
    while True:
        user_id = input("Enter user id: ")
        get_already(user_id)
        get_recomendations(user_id)
    
if __name__ == "__main__":
   main()

