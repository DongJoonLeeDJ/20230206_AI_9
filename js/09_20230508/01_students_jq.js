$(
    function()
    {
        //$ = document
        const name = $('#name')
        const gender = $('#gender')
        const beonho = $('#beonho')

        const del = $('#del')
        const modify = $('#modify')
        const select = $('#select')
        const all_select = $('#all_select')

        const print = $('#print')
        const reset = $('#reset')
        const printOrderBy = $('#printOrderBy')
        const information = $('#information')

        function resetInfo() {
            information.text('') //information태그 안에 있는 글자들을 제거
        }
        //화면이랑 데이터 전부 초기화 함
        reset.on('click', function(){
            resetInfo()
            students = [] //students.js에서 가져온 배열
        })

        print.click(function(){
            const student = 
            new Student(name.val(),gender.val(),Number(beonho.val()))
            let newStudentInfo = $('<h1></h1>')//새로운 h1태그 생성
            newStudentInfo.text(student.toString())
            if(student.gender=='남')
                newStudentInfo.css('background-color','cyan').
                css('color', 'blue')
            else if(student.gender=='여')
                newStudentInfo.css('background-color','pink').
                css('color', 'red')
            else
                newStudentInfo.css('border','1px solid black')
            
            information.append(newStudentInfo)
            
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
                let newStudentInfo = $('<h1></h1>')
                newStudentInfo.text(item.toString())
                if(item.gender=='남')
                     newStudentInfo.css('background-color','cyan').css('color', 'blue')
                else if(item.gender=='여')
                     newStudentInfo.css('background-color','pink').css('color', 'red')
                else
                    newStudentInfo.css('border','1px solid black')
                information.append(newStudentInfo)

            }
        }

        printOrderBy.on('click', function(){
            //findIndex : 객체 배열에서 특정한 조건을 만족하는
            //배열 요소의 인덱스를 반환하는 함수
            //매개변수 : 콜백함수를 이용함\
            const idx = students.findIndex(function(item){
                return item.beonho == Number(beonho.val())
            })
            if(idx!=-1)
            {
                alert('중복된 번호!')
                return //click 이벤트 강제 종료
            }
            resetInfo()
            students.push(new Student(name.val(),gender.val(),
            Number(beonho.val())))
            printStudentsOrderBy()
        })

        del.on('click', function(){
            const idx = students.findIndex(function(item){
                return item.beonho == Number(beonho.val())
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

        modify.on('click',function(){
            const idx = students.findIndex(function(item){
                return item.beonho == Number(beonho.val())
            })
            if(idx==-1)
            {
                alert('없는 학생입니다.')
                return
            }
            students[idx]['name']= name.val()
            students[idx].gender = gender.val()
            students[idx].beonho = Number(beonho.val())
            resetInfo()
            printStudentsOrderBy()
        })

        select.on('click', function(){
            const idx = students.findIndex(function(item){
                return item.beonho == Number(beonho.val())
            })
            if(idx==-1)
            {
                alert('없는 학생입니다.')
                return
            }
            resetInfo()
            let newStudentInfo = $('<h1></h1>')
            newStudentInfo.text(students[idx].toString())
            if(students[idx].gender=='남')
                newStudentInfo.css('background-color','cyan')
                .css('color', 'blue')
            else if(students[idx].gender=='여')
                newStudentInfo.css('background-color','pink')
                .css('color', 'red')
            else
                newStudentInfo.css('border', '1px solid black') 
            information.append(newStudentInfo)        
        })
        
        all_select.on('click', function(){
            resetInfo()
            printStudentsOrderBy()
        })

    }
)