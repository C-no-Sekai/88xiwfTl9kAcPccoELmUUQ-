import sqlite3 as sql
con = sql.connect('VRBankDB.db')
cur = con.cursor()
#cur.execute("UPDATE ACCOUNTS SET Balance = 10000, interest = 0")
#cur.execute("INSERT INTO TRANSACTIONS (sender, receiver, amount, time) SELECT 'BankInterest', username, interest, 'Fri Mar 12 2021' FROM ACCOUNTS WHERE type = 'S';")
#cur.execute("ALTER TABLE ACCOUNTS ADD loanInterest currency;")
#cur.execute("UPDATE ACCOUNTS SET loanInterest = 0;")
Sender = "admin"
receiver = "test"
amount = "100"
def getCurrentDT():
    return "Fri 10 Mar 2022"

#cur.execute("INSERT INTO TRANSACTIONS VALUES('" + Sender + "', '" + receiver + "', " + amount + " ,'" + getCurrentDT() + "');")
cur.execute("DELETE FROM TRANSACTIONS WHERE time = 'Fri 10 Mar 2022' OR time = 'Fri Mar 12 2021';")
tax = 20
savingsChange = 10
print("ACCOUNTS\n")
for i in cur.execute('SELECT * FROM ACCOUNTS;'):
    print(i)
print()
print("TRANSACTIONS\n")
for i in cur.execute('SELECT * FROM TRANSACTIONS;'):
    print(i)

con.commit()
con.close()
