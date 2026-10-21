import { ComponentFixture, TestBed } from '@angular/core/testing';

import { ResidenceFormComponent } from './residence-form.component';

describe('ResidenceFormComponent', () => {
  let component: ResidenceFormComponent;
  let fixture: ComponentFixture<ResidenceFormComponent>;

  beforeEach(() => {
    TestBed.configureTestingModule({
      declarations: [ResidenceFormComponent]
    });
    fixture = TestBed.createComponent(ResidenceFormComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
