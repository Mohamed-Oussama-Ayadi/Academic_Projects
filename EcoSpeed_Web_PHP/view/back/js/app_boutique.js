$(document).ready(function(){
	$.ajax({
		url: "http://localhost/integration/view/back/statistiques_boutique.php",
		method: "GET",
		success: function(data) {
			console.log(data);
			var boutique = [];
			var nbre_voitures = [];

			for(var i in data) {
				boutique.push("boutique " + data[i].id);
				nbre_voitures.push(data[i].nbre_voitures);
			}

			var chartdata = {
				labels: boutique,
				datasets : [
					{
						label: 'Nombre de voitures par boutique',
						backgroundColor: 'rgba(0,0,128)',
						borderColor: 'rgba(0,0,128)',
						hoverBackgroundColor: 'rgba(0,0,128)',
						hoverBorderColor: 'rgba(0,0,128)',
						data: nbre_voitures
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