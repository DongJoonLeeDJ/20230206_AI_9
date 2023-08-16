from konlpy.tag import Komoran
import numpy as np

kom = Komoran()
text = "오늘 날씨는 구름이 많아요"

#명사만 추출
nouns = kom.nouns(text)
print(nouns)

#단어 사전을 구축하고 단어별로 인덱스 부여
#-> 원 핫 인코딩 수행 준비 작업
dics = {} #dict = dictionary = js의 객체
# '오늘' : 0, '날씨' : 1, '구름' : 2
for item in nouns:
    if item not in dics.keys():
        dics[item] = len(dics)
print(dics)

#원 핫 인코딩을 생성함
one_hot_length = len(dics) # 3
targets = list(dics.values()) #[0,1,2]
print(targets)
print(list(dics.keys())) #['오늘','날씨','구름']
one_hot_targets = (
    np.eye(one_hot_length))[targets]
# 단위 행렬을 만드는 것
print(one_hot_targets)