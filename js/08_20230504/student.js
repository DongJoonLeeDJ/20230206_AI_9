class Student {
    constructor(name,gender,beonho){
        this.name = name
        this.gender = gender
        this.beonho = beonho
    }
}
Student.prototype.toString = function(){
    return `${this.name}학생은 `+
    `${this.gender}학생이며, ${this.beonho}번이다.`
}

let students = [] //학생 여러명 담을 배열