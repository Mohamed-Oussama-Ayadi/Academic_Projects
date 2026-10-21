import { NgModule } from '@angular/core';
import { RouterModule, Routes } from '@angular/router';
import { ResidencesComponent } from './residences/residences.component';
import { ApartementComponent } from './apartement/apartement.component';
import { HomeComponent } from './home/home.component';
import { NotFoundComponent } from './not-found/not-found.component';
import { ResidenceDetailsComponent } from './residence-details/residence-details.component';
import { ResidenceFormComponent } from './residence-form/residence-form.component';
const routes: Routes = [
  {path:'',redirectTo:'residences',pathMatch:"full"},
  {path:'home', component:HomeComponent},
  {path:'residences', component:ResidencesComponent, children:[
    {path:"details/:id", component:ResidenceDetailsComponent},
  ]},

  
  // {path:"details/:id", component:ResidenceDetailsComponent},
  {path:'apartments', component:ApartementComponent},
  {path:'addResidence', component:ResidenceFormComponent},
  {path:"**", component:NotFoundComponent},

];

@NgModule({
  imports: [RouterModule.forRoot(routes)],
  exports: [RouterModule]
})
export class AppRoutingModule { }
