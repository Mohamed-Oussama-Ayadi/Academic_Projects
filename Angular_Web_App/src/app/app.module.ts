import { NgModule } from '@angular/core';
import { BrowserModule } from '@angular/platform-browser';

import { AppRoutingModule } from './app-routing.module';
import { AppComponent } from './app.component';
import { CardComponent } from './card/card.component';
import { FormsModule, ReactiveFormsModule } from '@angular/forms';
import { ResidencesComponent } from './residences/residences.component';
import { HeaderComponent } from './header/header.component';
import { FooterComponent } from './footer/footer.component';
import { ApartementComponent } from './apartement/apartement.component';
import { HomeComponent } from './home/home.component';
import { NotFoundComponent } from './not-found/not-found.component';
import { ResidenceDetailsComponent } from './residence-details/residence-details.component';
import { ResidenceFormComponent } from './residence-form/residence-form.component';

@NgModule({
  declarations: [
    AppComponent,
    CardComponent,
    ResidencesComponent,
    HeaderComponent,
    FooterComponent,
    ApartementComponent,
    HomeComponent,
    NotFoundComponent,
    ResidenceDetailsComponent,
    ResidenceFormComponent
  ],
  imports: [
    BrowserModule,
    AppRoutingModule,
    FormsModule,
    ReactiveFormsModule
  ],
  providers: [],
  bootstrap: [AppComponent]
})
export class AppModule { }
