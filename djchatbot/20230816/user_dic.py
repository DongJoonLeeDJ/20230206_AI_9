from konlpy.tag import Komoran
ko = Komoran()
text = "우리 챗봇은 엔엘피를 사용해."
pos = ko.pos(text)
print(pos)

myko = Komoran(userdic='./user_dic.tsv')
text = "우리 챗봇은 엔엘피를 사용해."
pos = myko.pos(text)
print(pos)


#[('우리', 'NP'),
# ('챗봇은', 'NA'),
# ('엔', 'NNB'),
# ('엘', 'NNP'),
# ('피', 'NNG'),
# ('를', 'JKO'),
# ('사용', 'NNG'),
# ('하', 'XSV'),
# ('아', 'EF'),
# ('.', 'SF')]