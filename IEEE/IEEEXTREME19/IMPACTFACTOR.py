import json
import math
t = int(raw_input())

s = raw_input()
d = json.loads(s)

article = {}
cite = {}
name = {}
good = {}

#Processing of the publications
for e in d["publications"]:
  num = int(e["publicationNumber"])
  good[num] = 1
  name[num] = e["publicationTitle"]
  article[name[num]] = 0
  cite[name[num]] = 0
  l = e["articleCounts"]
  for i in l:
    if(i["year"] in ["2017","2018"]):
      article[name[num]] += int(i["articleCount"])


while(t-1):
  s = raw_input()
  d = json.loads(s)
  l = d["paperCitations"]["ieee"]
  for i in l:
    num = int(i["publicationNumber"])
    year = i["year"]
    if(num in good and year in ["2017","2018"]):
      cite[name[num]] += 1
  # print(d["publications"])
  t-=1

f = {}
for key in article:
  f[key] = float(cite[key])/article[key]

l = []
for key in f:
  l.append([-f[key],key])

l.sort()

for i in l:
  print(i[1]+":"),
  print("%.2f" % math.fabs(i[0]))

# print article,cite