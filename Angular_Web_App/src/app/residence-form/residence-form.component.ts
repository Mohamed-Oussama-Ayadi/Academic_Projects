import { Component } from '@angular/core';
import { FormControl, FormGroup } from '@angular/forms';

@Component({
  selector: 'app-residence-form',
  templateUrl: './residence-form.component.html',
  styleUrls: ['./residence-form.component.css']
})
export class ResidenceFormComponent {

resForm! :FormGroup;

  ngONInit(){
this.resForm = new FormGroup({
  id: new FormControl(null),
  name: new FormControl(null),
  adress: new FormControl(null),
  image: new FormControl(null),
  status: new FormControl(null),

  });
}
}
