
function checkInput(){
	var username = document.forms["form2"]["username"].value;
	var password1 = document.forms["form2"]["password"].value;
	if (username == "" || password1 == "") {
		alert("信息不能为空");
		return false;
	}else if (username.length < 7 || username.length>15||!username.match("^[a-zA-Z][a-zA-Z0-9]{6,15}$")) {
		alert("用户名格式不规范");
		return false;
	} else if (password1.length < 7 || password1.length > 15 || !password1.match("^[0-9]{6,15}$")){
		alert("密码长度不能小于7位或者大于15位或者密码非纯数字！");
		return false;
	} else if (username.length >= 7 && username.length <= 15
			&& password1.length > 6 && password1.match("^[0-9]{6,15}$")
			&& username.match("^[a-zA-Z][a-zA-Z0-9]{6,15}$")) {
		return true;
	}
}