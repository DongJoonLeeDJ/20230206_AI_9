window.onload = function() {
    const star = document.querySelector('h1')
    star.style.position = 'fixed'
    let [x,y] = [0,0] //x라는 변수와 y라는 변수에 각각 0 대입
    const block = 20 //20칸 단위로 움직인다.
    //별의 위치를 옮겨주는 함수
    const print = function() {
        star.style.left = `${x*block}px`
        star.style.top = `${y*block}px`
    }
    print() //별을 0,0에 위치시킴
    //키 코드값 : 왼쪽 화살표의 코드값은 37로 정해져있음
    //js에서 정해진 것임
    const [left,up,right,down] = [37,38,39,40]
    document.body.addEventListener('keydown', 
    function(event)
    {
        switch(event.keyCode) {
            case left://37인 경우
                if (x > 0){
                    x-=1
                }
                
                break
            case right:
                
            if (x < screen.width ){
                    x+=1
                }
                break
            case up:
                y-=1
                break
            case down:
                y+=1
                break
        }
        print()
    })
}