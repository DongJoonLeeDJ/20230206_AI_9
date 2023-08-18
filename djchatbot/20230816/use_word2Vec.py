from gensim.models import Word2Vec
model = Word2Vec.load('nvmc.model')
print('사랑 : ',model.wv['사랑'])

print('일요일 = 월요일',model.wv.similarity(w1='일요일',w2='월요일'))
print('히어로 = 영웅',model.wv.similarity(w1='히어로',w2='영웅'))
print('영웅 = 삼성' ,model.wv.similarity(w1='영웅',w2='삼성'))
print('히어로 = 삼성' ,model.wv.similarity(w1='히어로',w2='삼성'))

print(model.wv.most_similar('영웅',topn=10))
print(model.wv.most_similar('시리즈',topn=10))
