$(function() {
    // 오디오 태그들
    //const sounds = document.querySelectorAll('audio')
    const sounds = $('audio')
    //클래스이름이 pads인 태그의 후손div들
    //const pads = document.querySelectorAll('.pads div')
    const pads = $('.pads div')
    //왜 const를 쓸까? 그냥 let 쓰면 안 돼?
    //1. 변동 안 됨
    //2. (책 참고) 메모리 관리할 때 용이함
    //const visual = document.querySelector('.visual')
    const visual = $('.visual')
    //const title = document.querySelector('.title')
    const title = $('.title')
    //.pad1~.pad6의 색상을 담는 배열
    const colors = ['red','orange','yellow','green','blue','plum']

    //audio 태그들에 대하여 일괄적으로 반복문 이용하여 이벤트 적용
    // sounds.forEach(
    //     function(soundFile) {
    //         //종료되면
    //         soundFile.onended=function(){
    //             visual.innerHTML=''
    //             title.innerHTML=''
    //         }
    //     }
    // )
    sounds.each(function(index,soundFile) {
        soundFile.onended = function(){
            visual.text('')
            title.text('')
        }
    })
    // pads.forEach(function(pad, index) {
    //     //pad.onclick = function(){}
    //     pad.addEventListener('click', function(){
    //         sounds.forEach(function(inx) {
    //             inx.pause() //sound들 전부를 멈춤
    //         })
    //         if(sounds[index])
    //         {
    //             //처음부터 다시 재생한다는 의미
    //             sounds[index].currentTime=0
    //             sounds[index].play()
    //             const strArray = sounds[index].src.split('sound/')
    //             title.innerHTML = strArray[1].split('.')[0] //파일명추출
    //         }
    //         createBubbles(index)
    //     })
    // })
    pads.each(function(index,pad){
        $(pad).on('click', function() {
            sounds.each(function(index,soundFile){
                soundFile.pause()
            })
            if(sounds[index]) {
                sounds[index].currentTime=0
                sounds[index].play()

                const strArray = sounds[index].src.split('sound/')
                title.text(strArray[1].split('.')[0])
            }
            createBubbles(index)
        })

    })

    const createBubbles = function(index) {
        //visual.innerHTML = ''
        visual.text('')
        //const bubble = document.createElement('div')
        const bubble = $('<div></div>') //div 태그 생성
        //visual.appendChild(bubble) //div 태그 만들어서 삽입
        visual.append(bubble) //jQ에선 append, js에선 appendChild
        //bubble.style.backgroundColor=colors[index]
        //bubble.style.top='300px'
        //bubble.style.animation = 'animation 2000ms linear infinite both'
        bubble.css('background',colors[index]).css('top','300px').
        css('animation','animation 2000ms linear infinite both')
    }

})