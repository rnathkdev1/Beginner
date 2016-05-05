using UnityEngine;
using System.Collections;

[System.Serializable]
public class Boundary{
	public float xmin , xmax , zmin, zmax;
}

public class PlayerController : MonoBehaviour {

	private Rigidbody rb;
	public float speed;
	public float tilt;

	public Boundary boundary;

	public GameObject shot;
	public Transform shotSpawn;
	public float fireRate;

	private float nextFire;	

	void Start(){
		
		rb = GetComponent<Rigidbody> ();
	}

	void Update(){
		if (Input.GetButton ("Fire1") && Time.time > nextFire) {
			nextFire = Time.time + fireRate;

			Instantiate (shot, shotSpawn.position, shotSpawn.rotation);
		}

	}
	// Update is called once per frame
	void FixedUpdate () {
		
		float moveHorizontal = Input.GetAxis ("Horizontal");
		float moveVertical = Input.GetAxis ("Vertical");

		Vector3 movement = new Vector3 (moveHorizontal, 0.0f, moveVertical);
		rb.velocity = speed*movement;

		rb.position = new Vector3 
			(Mathf.Clamp (rb.position.x, boundary.xmin, boundary.xmax), 
				0.0f, 
				Mathf.Clamp (rb.position.z, boundary.zmin, boundary.zmax)
			);

		rb.rotation = Quaternion.Euler (0.0f, 0.0f, rb.velocity.x * -tilt);
	}
}
