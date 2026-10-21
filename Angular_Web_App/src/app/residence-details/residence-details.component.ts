import { Component } from '@angular/core';
import { ActivatedRoute } from '@angular/router';
import { Residence } from '../core/models/Residence';

@Component({
  selector: 'app-residence-details',
  templateUrl: './residence-details.component.html',
  styleUrls: ['./residence-details.component.css']
})
export class ResidenceDetailsComponent {
  id:number|undefined;
  res:Residence|undefined;
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
constructor(private act:ActivatedRoute){}

ngOnInit(){
  this.id=this.act.snapshot.params['id'];
  this.act.paramMap.subscribe(param=>{this.id= Number (param.get('id'));
    this.res=this.listResidences.find(res=>res.id===this.id)
  })
 
}
}
