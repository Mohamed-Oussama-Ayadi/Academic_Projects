from flask import Blueprint, request, jsonify
from werkzeug.security import check_password_hash
from flask_jwt_extended import create_access_token, jwt_required, get_jwt_identity
from models import User
from extensions import db

auth_bp = Blueprint('auth', __name__)

@auth_bp.route('/api/login', methods=['POST'])
def login():
    data = request.json
    user = User.query.filter_by(email=data.get('email')).first()
    if user and check_password_hash(user.password, data.get('password')):
        access_token = create_access_token(identity={'email': user.email, 'role': user.role})
        return jsonify(access_token=access_token), 200
    return jsonify(msg="Invalid credentials"), 401

@auth_bp.route('/api/profile', methods=['GET'])
@jwt_required()
def profile():
    return jsonify(get_jwt_identity()), 200

@auth_bp.route('/api/check-role/<role>', methods=['GET'])
@jwt_required()
def check_role(role):
    identity = get_jwt_identity()
    return jsonify(match=(identity.get('role') == role)), 200
