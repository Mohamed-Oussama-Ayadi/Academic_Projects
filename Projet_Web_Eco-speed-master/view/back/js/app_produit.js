$(document).ready(function(){
	$.ajax({
		url: "http://localhost/integration/view/back/statistique_produit.php",
		method: "GET",
		success: function(data) {
			console.log(data);
			var produit = [];
			var quantite = [];

			for(var i in data) {
				produit.push("produit " + data[i].nom);
				quantite.push(data[i].quantite);
			}

			var chartdata = {
				labels: produit,
				datasets : [
					{
						label: 'Produit',
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