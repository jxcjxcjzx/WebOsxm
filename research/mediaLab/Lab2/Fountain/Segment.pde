class Segment {

  private float start;
  private float duration;
  private float startLoudness;
  private float endLoudness;
  private float maxLoudness;
  private float maxLoudnessTimeOffset;
  private float[] pitches = new float[0];
  private float[] timbre = new float[0];

  /**
   * Gets the duration of the segment
   * @return the duration of the segment in seconds
   */
  public float getDuration() {
    return duration;
  }

  void setDuration(float duration) {
    this.duration = duration;
  }

  /**
   * Gets the maximum loudness
   * @return the loudness in dB
   */
  public float getMaxLoudness() {
    return maxLoudness;
  }

  void setMaxLoudness(float maxLoudness) {
    this.maxLoudness = maxLoudness;
  }

  /**
   * Gets the time within the segment with the maximum loudness occurs
   * @return the time in seconds
   */
  public float getMaxLoudnessTimeOffset() {
    return maxLoudnessTimeOffset;
  }

  void setMaxLoudnessTimeOffset(float maxLoudnessTimeOffset) {
    this.maxLoudnessTimeOffset = maxLoudnessTimeOffset;
  }

  /**
   * Gets the pitch information for the segment
   * @return the normalized strength of each of the 12 pitches
   */
  public float[] getPitches() {
    return pitches;
  }

  void setPitches(float[] pitches) {
    this.pitches = pitches;
  }

  /**
   * Gets the starting time of the segment
   * @return the start time in seconds
   */
  public float getStart() {
    return start;
  }

  void setStart(float start) {
    this.start = start;
  }

  /**
   * Gets the loudness at the start of the segment
   * @return the loudness in dB
   */
  public float getStartLoudness() {
    return startLoudness;
  }

  void setStartLoudness(float startLoudness) {
    this.startLoudness = startLoudness;
  }

  /**
   * Gets the loudness at the end of the segment
   * @return the loudness in dB
   */
  public float getEndLoudness() {
    return endLoudness;
  }

  void setEndLoudness(float endLoudness) {
    this.endLoudness = endLoudness;
  }

  /**
   * Gets the timbre coefficients
   * @return the timbre coefficients
   */
  public float[] getTimbre() {
    return timbre;
  }

  void setTimbre(float[] timbre) {
    this.timbre = timbre;
  }

  public String toString() {
    StringBuilder sb = new StringBuilder();
    sb.append("Start: " + start + " Dur: " + duration + "\n");
    sb.append("Loudness  start: " + startLoudness +
      " end: " + endLoudness +
      " max " + maxLoudness + " at " + maxLoudnessTimeOffset + "\n");

    sb.append("Pitches: ");
    for (int i = 0; i < pitches.length; i++) {
      sb.append(pitches[i] + " ");
    }
    sb.append("\n");

    sb.append("Timbre: ");
    for (int i = 0; i < timbre.length; i++) {
      sb.append(timbre[i] + " ");
    }
    sb.append("\n");

    return sb.toString();
  }
}


