import { Component } from '@angular/core';

@Component({
  selector: 'app-card',
  templateUrl: './card.component.html',
  styleUrls: ['./card.component.css']
})
export class CardComponent {

  title:string="smart screen";
  textcolor:string="blue";
  plc:string="quantité";
  qty:string="";
  date =new Date();

  getQuantity(){
    return alert("la quantité est  "+ this.qty);
  }

}
