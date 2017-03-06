var express = require('express'),
app = express();
var session = require('express-session')
var crypto = require('crypto');
var url = require('url');
var querystring = require('querystring');	
var bodyParser = require('body-parser');
var mongoose = require('mongoose');
var jsonSelect = require('mongoose-json-select');
console.log(mongoose.version);

	var db = mongoose.connection;//Когда
 
	app.use(express.static(__dirname + '/chat'));

	db.on("error", console.error.bind(console, "connection error:"));//подклчюение к базе
	db.once("open", function callback () {
		console.log("Connected!");
	});

	var userSchema = new mongoose.Schema({
		login: String,
		password: String
	});
	
	var commentSchema = new mongoose.Schema({
		text: String,
		author: String,
		date: String
	});



	var UserModel = mongoose.model('User', userSchema, 'User');
	
	var CommentModel = mongoose.model('Comment', commentSchema, 'Comment');


	var myHash = function (msg) {
		return crypto.createHash('sha256').update(msg).digest('hex');
	};

	var myTime = function () {
		var MyDate = new Date();
		MyDate.setDate(MyDate.getDate());
		var MyDateString = ('0' + MyDate.getHours()).slice(-2) + ':' + ('0' + MyDate.getMinutes()).slice(-2) + ':' + ('0' + MyDate.getSeconds()).slice(-2) + '  ' + ('0' + MyDate.getDate()).slice(-2) + '.' + ('0' + (MyDate.getMonth()+1)).slice(-2) + '.' + MyDate.getFullYear();
		return MyDateString;
	};


	
	app.use(session({ secret: 'lgbldhbuwamkaboyiu327cflbz',cookie: { maxAge: 1200000 }}));//Объявление сессии, время жизни в милисекундах
	app.use(bodyParser());//Преобразование в Json тела запроса POST (ПАРСИНГ)

	var sess;//Переменная сессии

	app.get('/exit', function(req, res){//Выход из сессии
		req.session.destroy();
		console.log('User '+ sess.login +' log out ['+myTime()+']');
		res.redirect('/');
	});
		

	app.get('/value/:status', function (req, res) {//Ответ AJAX'су подгрузка сообщений
  		CommentModel.find({},function (err, docs){
			if (err) res.send(err)
			var out = JSON.parse(JSON.stringify(docs));
		
			if(out.length < 10){
				for(var i=0; i!=out.length; i++){
				var time;
				if(out[i].date.substring(10,20) == myTime().substring(10,20)){
					time = out[i].date.substring(0,5);
				}else{
					time = out[i].date.substring(0,5)+' '+out[i].date.substring(10,20);
				}
				res.write('<div>'+time+' ['+out[i].author+'] '+out[i].text+'</div>');						
				}
				res.write('     '+out.length+'');//Дописываем число комментариев в базе для нашего скрипта на клиентской стороне
			}
			else{
				for(var i=out.length-10; i!=out.length; i++){
				var time;
				if(out[i].date.substring(10,20) == myTime().substring(10,20)){
					time = out[i].date.substring(0,5);
				}else{
					time = out[i].date.substring(0,5)+' '+out[i].date.substring(10,20);
				}
				res.write('<div>'+time+' ['+out[i].author+'] '+out[i].text+'</div>');						
				}
				res.write('     '+out.length+'');//Дописываем число комментариев в базе для нашего скрипта на клиентской стороне		
			}
			res.end();
		});
	});
	
		app.post('/comment', function(req, res){//Добавления комментария
		sess = req.session;
		if(!req.body.text){//Проверка на пустоту
			return
		}
		if(sess.login){
			//Метод Новая запись
			var addComment = new CommentModel({
				text: req.body.text,
				author: sess.login,
				date: myTime()
			});
			addComment.save(function(err, addComment) {
				if (err) return console.error(err);
				console.log('User '+sess.login+' add comment: "'+req.body.text+'" ['+myTime()+']');
			});
				//Конец записи
		}
		res.redirect('/'); 
	});	


 fs = require('fs');//Считываем файлв в переменную для формирования страницы
 fs.readFile('./unsign.html', function (err, html) {
	   if (err) { throw err; }
fs.readFile('./chat.html', function (err, chat) {
  if (err) { throw err; }
  
 	app.get('/', function(req, res){//Формирование главной страницы в зависимости от сессии
		sess=req.session;
		if(sess.login){	
			res.writeHead(200, {'Content-Type': 'text/html; charset=utf-8'})//Формиримуем страницу для авторизованных пользователей
			res.write('      <a href="/exit">Exit</a>');
		//Окно чата
		res.write(chat);
		res.end();


		}else{	
			res.writeHead(200, {'Content-Type': 'text/html; charset=utf-8'})//Формиримуем страницу для неавторизованных пользователей
			res.write(html);//Подгружаем файл с формами авторизации и регистрации
			res.end();
		}
		
	}); 
  }); 
  
  
	
	app.post('/registr', function(req, res){//Регистрация	
		
		var userlogin = req.body.login.toLowerCase();
		var userpassword = myHash(req.body.password);
		
		if(!userlogin || !req.body.password){//Проверка на пустоту
				res.writeHead(200, {'Content-Type': 'text/html; charset=utf-8'})//Формиримуем страницу для авторизованных пользователей
				res.write('<p align="center" style="color: red;">Заполните все поля.</p>');
				res.write(html);
				res.end();
			return
		}
   
		UserModel.findOne({'login':userlogin},function (err, docs){
			if (err) res.send(err)
			var out = JSON.parse(JSON.stringify(docs));

			if(out){
				res.writeHead(200, {'Content-Type': 'text/html; charset=utf-8'})//Формиримуем страницу для авторизованных пользователей
				res.write('<p align="center" style="color: red;">Пользователь с таким именем уже существует.</p>');
				res.write(html);
				res.write('<script type="text/javascript">\n');//Скрипт повторного отражения формы регистрации при ошибке
				res.write('window.onload = function() {');
				res.write('$(\'#log\').hide();\n');
				res.write('$(\'#reg\').show();\n');
				res.write('$(\'#btn_log\').show();\n');
				res.write('$(\'#btn_reg\').hide();\n');
				res.write('}');
				res.write('</script>\n');
				res.end();
			}else{
				//Метод Новая запись
				var addUser = new UserModel({
					login: userlogin,
					password: userpassword
				});

				addUser.save(function(err, addUser) {
					if (err) return console.error(err);
					console.log('User '+userlogin+' registered ['+myTime()+']');
				});
				//Конец записи
				

				res.writeHead(200, {'Content-Type': 'text/html; charset=utf-8'})//Формиримуем страницу для авторизованных пользователей
				res.write('<p align="center" style="color: green;">Регистрация прошла успешно, теперь Вы можете авторизоваться.</p>');
				res.write(html);
				res.end();
			}

		});
		

	});	


	app.post('/login', function(req, res){//Авторизация
		
		sess=req.session;
		var userlogin = req.body.login.toLowerCase();
		var userpassword = myHash(req.body.password);
		
		if(!userlogin || !req.body.password){//Проверка на пустоту
			res.writeHead(200, {'Content-Type': 'text/html; charset=utf-8'})//Формиримуем страницу для авторизованных пользователей
			res.write('<p align="center" style="color: red;">Заполните все поля.</p>');
			res.write(html);
			res.end();
			return
		}

		UserModel.findOne({'login':userlogin,'password':userpassword},function (err, docs){

			var out = JSON.parse(JSON.stringify(docs));

			if(out){
				console.log('User '+ userlogin +' logged ['+myTime()+']');
				sess.login = userlogin;
				res.redirect('/');
			}else{
				res.writeHead(200, {'Content-Type': 'text/html; charset=utf-8'})//Формиримуем страницу для авторизованных пользователей
				res.write('<p align="center" style="color: red;">Неправильный Логин или Пароль.</p>');
				res.write(html);
				res.end();
			}
		
		});
    
    
	});  
 });	


app.listen(8080);
mongoose.connect('mongodb://localhost/chat');//Куда