import { ComponentFixture, TestBed } from '@angular/core/testing';

import { ApartementComponent } from './apartement.component';

describe('ApartementComponent', () => {
  let component: ApartementComponent;
  let fixture: ComponentFixture<ApartementComponent>;

  beforeEach(() => {
    TestBed.configureTestingModule({
      declarations: [ApartementComponent]
    });
    fixture = TestBed.createComponent(ApartementComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
