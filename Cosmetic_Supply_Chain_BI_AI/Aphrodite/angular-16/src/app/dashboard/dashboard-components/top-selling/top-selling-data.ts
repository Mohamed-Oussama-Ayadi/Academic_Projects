export interface TeamMember {
  image: string;
  name: string;
  email: string;
  role: string;
}

export const Team: TeamMember[] = [
   {
    image: 'assets/images/users/photo de profil.jpg',
    name: 'Mohamed Oussama Ayadi',
    email: 'mohamedoussama.ayadi@aphrodite.com',
    role: 'Cheif Executive Officer'
  },
   {
    image: 'assets/images/users/dina.jpg',
    name: 'Dina Gharbi',
    email: 'dina.gharbi@aphrodite.com',
    role: 'Production Manager'
  },
  
  {
    image: 'assets/images/users/mariem.jpg',
    name: 'Mariem Boudhina',
    email: 'mariem.boudhina@aphrodite.com',
    role: 'Stock Manager'
  },
  {
    image: 'assets/images/users/aziza.jpg',
    name: 'Aziza Kallel',
    email: 'aziza.kallel@aphrodite.com',
    role: 'Stock Manager'
  },
 {
    image: 'assets/images/users/bilel.jpg',
    name: 'Billel Dabech',
    email: 'billel.dabech@aphrodite.com',
    role: 'Sales Manager'
  },
 {
    image: 'assets/images/users/malika.jpg',
    name: 'Malika Gharbi',
    email: 'malika.gharbi@aphrodite.com',
    role: 'Sales Manager'
  },
];
