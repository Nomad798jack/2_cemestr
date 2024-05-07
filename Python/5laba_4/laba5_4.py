import json
import csv

file_json = open("Sample-employee-JSON-data.json", "r")
data = json.load(file_json)
file_json.close()


file_csv = open("Sample-employee-CSV-data.csv", "w", newline = "")
writer = csv.DictWriter(file_csv, data["Employees"][0].keys())
writer.writeheader()
writer.writerows(data["Employees"])
file_csv.close()
