from konlpy.tag import Komoran

#어절 단위 n-gram
#bow : 원본
#num_gram : 몇 개의 어절로 자를 지
def word_ngram(bow, num_gram):
    text = tuple(bow)
    ngrams = [text[x:x+num_gram]
              for x in range(0,len(text))]
    return tuple(ngrams)
#유사도 계산
def similarity(doc1, doc2):
    cnt = 0
    for token in doc1:
        if token in doc2:
            cnt = cnt + 1
    return cnt/len(doc1)

s1 = '6월에 뉴턴은 선생님의 제안으로 트리니티에 입학하였다'
s2 = '6월에 뉴턴은 선생님의 제안으로 대학교에 입학하였다'
s3 = '6월에 뉴트리아는 선생님의 제안으로 트리니티에서 사냥하였다'
s4 = '나는 맛있는 밥을 뉴턴 선생님과 함께 먹었습니다'

komoran = Komoran()
bow1 = komoran.nouns(s1)
bow2 = komoran.nouns(s2)
bow3 = komoran.nouns(s3)
bow4 = komoran.nouns(s4)

doc1 = word_ngram(bow1,2)
doc2 = word_ngram(bow2,2)
doc3 = word_ngram(bow3,2)
doc4 = word_ngram(bow4,2)

r1 = similarity(doc1,doc2)
r2 = similarity(doc2,doc3)
r3 = similarity(doc1,doc3)
r4 = similarity(doc1,doc4)

print(r1)
print(r2)
print(r3)
print(r4)