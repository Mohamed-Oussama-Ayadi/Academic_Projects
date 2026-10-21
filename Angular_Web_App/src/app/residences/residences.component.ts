import { Component } from '@angular/core';
import { Residence } from '../core/models/Residence';

@Component({
  selector: 'app-residences',
  templateUrl: './residences.component.html',
  styleUrls: ['./residences.component.css'],
})
export class ResidencesComponent {
  listFavorite: Residence[] = [];
  item: string = '';
  listResidences: Residence[] = [
    {
      id: 1,
      name: 'El fel',
      address: 'Borj Cedria',
      image: '../../assets/images/R4.jpg',
      status: 'Disponible',
    },
    {
      id: 2,
      name: 'El yasmine',
      address: 'Ezzahra',
      image: '../../assets/images/R4.jpg',
      status: 'Disponible',
    },
    {
      id: 3,
      name: 'El Arij',
      address: 'Rades',
      image: '../../assets/images/R4.jpg',
      status: 'Vendu',
    },
    {
      id: 4,
      name: 'El Anber',
      address: 'inconnu',
      image: '../../assets/images/R4.jpg',
      status: 'En Construction',
    },
  ];

  showLocation(address: string) {
    if (address === 'inconnu') {
      return alert("l'adresse est inconnu");
    } else {
      return alert('l adresse est ' + address);
    }
  }

  addFavorite(residence: Residence) {
    if (!this.listFavorite.includes(residence)) {
      this.listFavorite.push(residence);
    }
  }

  filterByAdress(): Residence[] {
    return this.listResidences.filter((res) =>
      res.address.toLowerCase().includes(this.item.toLowerCase())
    );
  }
}
