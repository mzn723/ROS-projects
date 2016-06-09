; Auto-generated. Do not edit!


(cl:in-package pupil_tracker-msg)


;//! \htmlinclude gaze_position.msg.html

(cl:defclass <gaze_position> (roslisp-msg-protocol:ros-message)
  ((x
    :reader x
    :initarg :x
    :type cl:float
    :initform 0.0)
   (y
    :reader y
    :initarg :y
    :type cl:float
    :initform 0.0)
   (conf
    :reader conf
    :initarg :conf
    :type cl:float
    :initform 0.0)
   (rx
    :reader rx
    :initarg :rx
    :type cl:float
    :initform 0.0)
   (ry
    :reader ry
    :initarg :ry
    :type cl:float
    :initform 0.0))
)

(cl:defclass gaze_position (<gaze_position>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <gaze_position>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'gaze_position)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name pupil_tracker-msg:<gaze_position> is deprecated: use pupil_tracker-msg:gaze_position instead.")))

(cl:ensure-generic-function 'x-val :lambda-list '(m))
(cl:defmethod x-val ((m <gaze_position>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader pupil_tracker-msg:x-val is deprecated.  Use pupil_tracker-msg:x instead.")
  (x m))

(cl:ensure-generic-function 'y-val :lambda-list '(m))
(cl:defmethod y-val ((m <gaze_position>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader pupil_tracker-msg:y-val is deprecated.  Use pupil_tracker-msg:y instead.")
  (y m))

(cl:ensure-generic-function 'conf-val :lambda-list '(m))
(cl:defmethod conf-val ((m <gaze_position>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader pupil_tracker-msg:conf-val is deprecated.  Use pupil_tracker-msg:conf instead.")
  (conf m))

(cl:ensure-generic-function 'rx-val :lambda-list '(m))
(cl:defmethod rx-val ((m <gaze_position>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader pupil_tracker-msg:rx-val is deprecated.  Use pupil_tracker-msg:rx instead.")
  (rx m))

(cl:ensure-generic-function 'ry-val :lambda-list '(m))
(cl:defmethod ry-val ((m <gaze_position>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader pupil_tracker-msg:ry-val is deprecated.  Use pupil_tracker-msg:ry instead.")
  (ry m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <gaze_position>) ostream)
  "Serializes a message object of type '<gaze_position>"
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'x))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'y))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'conf))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'rx))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'ry))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <gaze_position>) istream)
  "Deserializes a message object of type '<gaze_position>"
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'x) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'y) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'conf) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'rx) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'ry) (roslisp-utils:decode-single-float-bits bits)))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<gaze_position>)))
  "Returns string type for a message object of type '<gaze_position>"
  "pupil_tracker/gaze_position")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'gaze_position)))
  "Returns string type for a message object of type 'gaze_position"
  "pupil_tracker/gaze_position")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<gaze_position>)))
  "Returns md5sum for a message object of type '<gaze_position>"
  "0e2f0ee6f3651fb6dedeca8dcf0988cb")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'gaze_position)))
  "Returns md5sum for a message object of type 'gaze_position"
  "0e2f0ee6f3651fb6dedeca8dcf0988cb")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<gaze_position>)))
  "Returns full string definition for message of type '<gaze_position>"
  (cl:format cl:nil "float32 x~%float32 y~%float32 conf~%float32 rx~%float32 ry~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'gaze_position)))
  "Returns full string definition for message of type 'gaze_position"
  (cl:format cl:nil "float32 x~%float32 y~%float32 conf~%float32 rx~%float32 ry~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <gaze_position>))
  (cl:+ 0
     4
     4
     4
     4
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <gaze_position>))
  "Converts a ROS message object to a list"
  (cl:list 'gaze_position
    (cl:cons ':x (x msg))
    (cl:cons ':y (y msg))
    (cl:cons ':conf (conf msg))
    (cl:cons ':rx (rx msg))
    (cl:cons ':ry (ry msg))
))
