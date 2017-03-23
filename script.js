
  ymaps.ready(function () {  
    var map = new ymaps.Map("myMap", {
          center: [57.63, 39.85], 
          zoom: 13
        });

  });

  //map.setCenter([80,90], 13);// [широта, долгота] -85<широта<85 -180<долгота<180
  var form = document.forms[0];
  
  form.addEventListener("submit", validate);

//проверяем верность формы
  function validate(event){
      var errors = document.querySelector(".alert.alert-error");
      if (errors)
        form.removeChild(errors);
      var target = event.target;
      var flags = {};
      var lat, long, name;
      if (lat = +target["lat"].value)
        {
          if (!(lat>=-85 && lat<=85))
            flags.lat = true;
        }
      else
        flags.lat = true;

      if (long = +target["long"].value)
        {
          if (!(long>=-180 && long<=180))
            flags.long = true;
        }
      else
        flags.long = true;

      if (!(name = target["name"].value))
        flags.name = true;
      var valid = true;
      for (key in flags)
        if (flags[key])
          valid = addAlert(key);
      if (valid)
        addMark({
          lat: lat,
          long: long,
          name: name
        });

      event.preventDefault(); //Предотвращаем отправку формы
  }

  function addAlert(key){
    switch(key){
      case "lat": alertLat();
        return false;
      case "long": alertLong();
        return false;
      case "name": alertName();
        return false;
    }
  }

  function alertLat(){
    var div;
    if (!(div = document.querySelector(".alert.alert-error")))
      {
        div = document.createElement("div");
        div.classList.add("alert");
        div.classList.add("alert-error");
        form.appendChild(div);
      }
    div.innerHTML += "Неправильная широта\n";
  }

  function alertLong(){
    var div;
    if (!(div = document.querySelector(".alert.alert-error")))
      {
        div = document.createElement("div");
        div.classList.add("alert");
        div.classList.add("alert-error");
        form.appendChild(div);
      }
    div.innerHTML += "Неправильная долгота\n";
  }

  function alertName(){
    var div;
    if (!(div = document.querySelector(".alert.alert-error")))
      {
        div = document.createElement("div");
        div.classList.add("alert");
        div.classList.add("alert-error");
        form.appendChild(div);
      }
    div.innerHTML += "Неправильное имя\n";
  }
//если правильно добавляем метку
  function addMark(options){
    alert("Добавил метку");
  }