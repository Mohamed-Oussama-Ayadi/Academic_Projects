class Config:
    SQLALCHEMY_DATABASE_URI = 'mysql+pymysql://root@localhost/cosmetics_auth_db'
    SQLALCHEMY_TRACK_MODIFICATIONS = False
    JWT_SECRET_KEY = 'your_secret_key_here'
