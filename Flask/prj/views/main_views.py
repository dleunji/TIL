from flask import Blueprint, render_template

from prj.models import Question
bp = Blueprint('main', __name__, url_prefix='/')


@bp.route('/hello')
def hello_pybo():
    return 'Hello, pybo!'

@bp.route('/')
def index():
    question_list = Question.query.order_by(Question.create_date.desc())
    retrun render_template('question/question_list.html', question_list=question_list)