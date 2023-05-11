class Student{
    constructor(name,gender,beonho)
    {
        //3개의 속성을 갖는 class
        this.name = name
        this.gender=  gender
        this.beonho = beonho
    }
}
Student.prototype.toString = function(){
    return `${this.name}학생은 ${this.gender}학생이며, ${this.beonho}번이다.`
}

let students = []