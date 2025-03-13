$(document).ready(function(){
	$.ajax({
		url: "http://localhost/integration/view/back/statistique_categorie.php",
		method: "GET",
		success: function(data) {
			console.log(data);
			var Categorie = [];
			var quantite = [];

			for(var i in data) {
				Categorie.push("Categorie " + data[i].nom);
				quantite.push(data[i].stock_max);
			}

			var chartdata = {
				labels: Categorie,
				datasets : [
					{
						label: 'Categorie',
						backgroundColor: 'rgba(0,0,205)',
						borderColor: 'rgba(0,0,205)',
						hoverBackgroundColor: 'rgba(0,0,205)',
						hoverBorderColor: 'rgba(0,0,205)',
						data: quantite
					}
				]
			};

			var ctx = $("#mycanvas");

			var barGraph = new Chart(ctx, {
				type: 'bar',
				data: chartdata
			});
		},
		error: function(data) {
			console.log(data);
		}
	});
});