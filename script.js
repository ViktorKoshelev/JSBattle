function Map(){
	var myMap = new ymaps.Map('myMap', {
        // центр и коэффициент масштабирования однозначно
        // определяют область картографирования
     center: [55.76, 37.64],
     zoom: 7
      });

}
function fail(){
	alert("Нихрена не загрузилось");
}

function good(){
	//alert("Карты есть");
}

  ymaps.ready(function () {  
    var map = new ymaps.Map("myMap", {
          center: [57.63, 39.85], 
          zoom: 13
        });

    
  });
