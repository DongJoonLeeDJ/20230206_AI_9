//window.onload = function(){}
//'DOMContentLoaded' 
//body 태그에 있는 내용들을 다 불러들인 뒤 라는 뜻
document.addEventListener('DOMContentLoaded',
    function()
    {
        const name = document.querySelector('#name')
        const gender = document.querySelector('#gender')
        const beonho = document.querySelector('#beonho')

        const del = document.querySelector('#del')
        const modify = document.querySelector('#modify')
        const select = document.querySelector('#select')
        const all_select = document.querySelector('#all_select')

        const print = document.querySelector('#print')
        const reset = document.querySelector('#reset')
        const printOrderBy = document.querySelector('#printOrderBy')
        const information = document.querySelector('#information')

        function resetInfo() {
            //information.text('') //information태그 안에 있는 글자들을 제거
            information.innerHTML = ''
        }
        //화면이랑 데이터 전부 초기화 함
        reset.addEventListener('click', function(){
            resetInfo()
            students = [] //students.js에서 가져온 배열
        })

        print.addEventListener('click',function(){
            const student = 
            //val() = value
            new Student(name.value,gender.value,
                Number(beonho.value))
            let newStudentInfo = document.createElement('h1')//새로운 h1태그 생성
            //newStudentInfo.text(student.toString())
            newStudentInfo.innerText = student.toString()
            if(student.gender=='남')
            {
                newStudentInfo.style.background='cyan'
                newStudentInfo.style.color='blue'
                //newStudentInfo.css('background-color','cyan').
                //css('color', 'blue')
            }
            else if(student.gender=='여')
            {
                newStudentInfo.style.background='pink'
                newStudentInfo.style.color='red'
                //newStudentInfo.css('background-color','pink').
                //css('color', 'red')
            }
            else
                newStudentInfo.style.border='1px solid black'
                //newStudentInfo.css('border','1px solid black')
            
            information.appendChild(newStudentInfo)
            
        })

        //학생들 정보를 번호순으로 뿌리기
        function printStudentsOrderBy()
        {
            //콜백함수 이용해서 students같은 객체 배열을
            //순차적으로 정렬
            students.sort(function(a,b){
                return a.beonho-b.beonho
            })
            for(const item of students)
            {
                let newStudentInfo = document.createElement('h1')
                //newStudentInfo.text(item.toString())
                newStudentInfo.innerText = item.toString()
                if(item.gender=='남')
                {
                    newStudentInfo.style.background='cyan'
                    newStudentInfo.style.color='blue'
                    //  newStudentInfo.css('background-color','cyan').css('color', 'blue')

                }
                else if(item.gender=='여')
                {
                    newStudentInfo.style.background='pink'
                    newStudentInfo.style.color='red'
                    //  newStudentInfo.css('background-color','pink').css('color', 'red')
                }
                else
                    newStudentInfo.style.border='1px solid black'
                    // newStudentInfo.css('border','1px solid black')
                information.appendChild(newStudentInfo)

            }
        }

        printOrderBy.addEventListener('click', function(){
            //findIndex : 객체 배열에서 특정한 조건을 만족하는
            //배열 요소의 인덱스를 반환하는 함수
            //매개변수 : 콜백함수를 이용함\
            const idx = students.findIndex(function(item){
                return item.beonho == Number(beonho.value)
            })
            if(idx!=-1)
            {
                alert('중복된 번호!')
                return //click 이벤트 강제 종료
            }
            resetInfo()
            students.push(new Student(name.value,gender.value,
            Number(beonho.value)))
            printStudentsOrderBy()
        })

        del.addEventListener('click', function(){
            const idx = students.findIndex(function(item){
                return item.beonho == Number(beonho.value)
            })
            if(idx==-1)
            {
                alert('없는 학생입니다.')
                return
            }
            students.splice(idx,1)//idx번째 있는 학생 삭제
            resetInfo() //화면 싹 지우고
            printStudentsOrderBy() //현재 목록을 다시 출력
        })

        modify.addEventListener('click',function(){
            const idx = students.findIndex(function(item){
                return item.beonho == Number(beonho.value)
            })
            if(idx==-1)
            {
                alert('없는 학생입니다.')
                return
            }
            students[idx]['name']= name.value
            students[idx].gender = gender.value
            students[idx].beonho = Number(beonho.value)
            resetInfo()
            printStudentsOrderBy()
        })

        select.addEventListener('click', function(){
            const idx = students.findIndex(function(item){
                return item.beonho == Number(beonho.value)
            })
            if(idx==-1)
            {
                alert('없는 학생입니다.')
                return
            }
            resetInfo()
            let newStudentInfo = document.createElement('h1')
            newStudentInfo.innerText = students[idx].toString()
            // newStudentInfo.text(students[idx].toString())
            if(students[idx].gender=='남')
            {
                newStudentInfo.style.background='cyan'
                newStudentInfo.style.color='blue'
                // newStudentInfo.css('background-color','cyan')
                // .css('color', 'blue')
            }
            else if(students[idx].gender=='여')
            {
                
                // newStudentInfo.css('background-color','pink')
                // .css('color', 'red')
                newStudentInfo.style.background='pink'
                newStudentInfo.style.color='red'
            }
            else
                newStudentInfo.style.border='1px solid black'
                //newStudentInfo.css('border', '1px solid black') 
            information.appendChild(newStudentInfo)        
        })
        
        all_select.addEventListener('click', function(){
            resetInfo()
            printStudentsOrderBy()
        })

    }
)